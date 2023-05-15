#!/usr/local/bin/bash

usage() {
echo -e -n "\nUsage: sahw2.sh {--sha256 hashes ... | --md5 hashes ...} -i files ...\n\n--sha256: SHA256 hashes to validate input files.\n--md5: MD5 hashes to validate input files.\n-i: Input files.\n"
}
declare -i hashfunc=0
declare -i hashcnt=0
declare -i inputcnt=0
declare -i nowexec=0 #0:sha256||md5, 1:input 
if [ $# -gt 0 ];  
then
	if [ $1 != "-h" ] && [ $1 != "-i" ] && [ $1 != "--sha256" ] && [ $1 != "--md5" ];then
		echo -n "Error: Invalid arguments." >>/dev/stderr
		usage
		exit 1
	fi
	for arg in "$@"
	do
	if [ $arg == "-h" ];then
		usage 
		exit 0
	elif [ $arg == "-i" ];then
		nowexec=1
	elif [ $arg == "--sha256" ];then
		if [ $hashfunc -gt 0 ];then
		echo -n "Error: Only one type of hash function is allowed." >>/dev/stderr
		exit 1
		fi
		nowexec=0
		hashfunc=1
	elif [ $arg == "--md5" ];then
		if [ $hashfunc -gt 0 ];then
		echo -n "Error: Only one type of hash function is allowed." >>/dev/stderr
		exit 1
		fi
		nowexec=0
		hashfunc=2
	elif [ $hashfunc -gt 0 ] && [ $nowexec == 0 ];then
		arr_hash[$hashcnt]=$arg	
		hashcnt+=1
	elif [ $nowexec == 1 ];then
		arr_input[$inputcnt]=$arg
		inputcnt+=1
	fi	
	done
	if [ $hashcnt != $inputcnt ];then
		echo -n "Error: Invalid values." >>/dev/stderr
		exit 1
	fi
	for(( i=0;i<${hashcnt}; i++));do
		if  [ $hashfunc == 1 ]&&[ $( cat ${arr_input[$i]}|sha256sum ) != ${arr_hash[$i]} ];then
			echo -n "Error: Invalid checksum." >>/dev/stderr
        	exit 1
		fi
		if  [ $hashfunc == 2 ]&&[ $( cat ${arr_input[$i]}|md5sum ) != ${arr_hash[$i]} ];then
			echo -n "Error: Invalid checksum." >>/dev/stderr
        	exit 1
		fi
	done
	for(( i=0;i<${hashcnt}; i++));do
		type=$(echo ${arr_input[$i]}|xargs file --mime-type -b) 
		if [ "$(head -n 1 ${arr_input[$i]})" != "username,password,shell,groups" ] && [ $type != "text/csv" ] && [ $type != "application/json" ];then
			echo -n "Error: Invalid file format." >>/dev/stderr
            exit 1
		fi
	done
	rm -rf userinfo.txt
	touch userinfo.txt
	echo -n "This script will create the following user(s): "
	for(( i=0;i<${hashcnt}; i++));do
		type=$(echo ${arr_input[$i]}|xargs file --mime-type -b) 
		if [ $type == "text/csv" ] || [ "$(head -n 1 ${arr_input[$i]})" == "username,password,shell,groups" ];then
			echo -n $(sed 1d ${arr_input[$i]}|cut -d , -f 1|xargs)
			sed 1d ${arr_input[$i]}|awk -F ',' '{print $1 " " $2 " " $3 " " $4}'>>userinfo.txt
		elif [ $type == "application/json" ];then
			echo -n $(cat ${arr_input[$i]}| jq -r ".[] | .username"|xargs)
			cat ${arr_input[$i]}|jq -r '.[] | [.username,.password,.shell,.groups[]]|join(" ")'>>userinfo.txt
		fi
		if [ $i != $hashcnt-1 ];then
	 		echo -n " "
		fi	
	done
	echo -n "Do you want to continue? [y/n]:"
	read -n1 option
	if [[ $option == "n" ]] || [[ -z "$option" ]];then
		exit 0
	fi
	while read line; do
		read -a arr <<< "$line"
		if  [ "$(getent passwd ${arr[0]})" ];then
			echo -n -e "\nWarning: user ${arr[0]} already exists."
		else
	
		pw useradd ${arr[0]}  -s ${arr[2]}
		echo "${arr[1]}" | pw usermod -n ${arr[0]} -h 0
		for((i=3;i<${#arr[@]};i++));do
		#echo ${arr[$i]}
		if ! [ $(getent group ${arr[$i]}) ];then
			pw groupadd ${arr[$i]}
		fi
			pw group mod ${arr[$i]} -m ${arr[0]}
			#echo "${arr[0]} -G ${arr[$i]}"
		done
		fi
			
	done < userinfo.txt
	#cat userinfo.txt >> /dev/stderr
	rm  -rf userinfo.txt
	
fi
