#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

struct passenger  {
    char account[300] ;
    char password[300];
    char birthday[300];
    char phonenumber[300];
    char email[300];
    struct passenger *next;
};

struct passenger *head = NULL;	//initial head is empty pointer
struct passenger *ptr = NULL;
struct passenger *cur = NULL;


void accountlogin(bool &qq)  ; // 登入
void accountlogin(bool &qq)  {
    char oo[300], pp[300];
    char line;
    cout << "請輸入帳號" << "\n" ;
    cin >> oo ;
    cout << "請輸入密碼" << "\n" ;
    cin >> pp ;
    cout << head->account;
    cout<<oo<<' '<<pp<<'\n';
    
    for ( cur = head->next ; cur != NULL ; cur = cur->next )  {
        cout<<cur->account<<"\n";
        if ( strcmp ( cur->account, oo ) == 0 &&  strcmp ( cur->password, pp ) == 0 )  {
            cout << "登入成功" << "\n";
            qq = true;
            break;
        } // if
        else if  ( strcmp ( cur->account, oo ) == 0 &&  strcmp ( cur->password, pp ) != 0 )  {
            cout << "帳號密碼錯誤" << "\n";
            qq =  false;
            break;
        } // else if
    } // for
        
    if ( cur->account == NULL )  {
        cout << "未註冊帳號" << "\n";
        qq = false;
    } // if
        
    return;
    
}  // accountlogin()

void ticket1() ;
void ticket1() {
    int a=0, b=0, c = 0, d = 0;
    
    cout << "請選擇出發站" << "\n";
    cout << "0.南港1.台北2.板橋3.桃園4.新竹5.苗栗6.台中7.彰化8.雲林9.嘉義10.台南11.左營" << "\n";
    cin >> a;
    cout << "請選擇到達站" << "\n";
    cout << "0.南港1.台北2.板橋3.桃園4.新竹5.苗栗6.台中7.彰化8.雲林9.嘉義10.台南11.左營" << "\n";
    cin >> b;
    cout << "請選擇票種" << "\n";
    cout << "1.全票2.半票" << "\n";
    cin >> c;
    cout << "請輸入張數" << "\n";
    cin >> d;
} // ticket1()

void register1()  ; // 註冊
void register1()  {

    ptr = (struct passenger *)malloc(sizeof(struct passenger));
    cout << "註冊帳號 >> " << "\n";
    cin >> ptr->account;
    cout << "註冊密碼 >> " << "\n";
    cin >> ptr->password;
    cout << "電話 >> " << "\n";
    cin >> ptr->phonenumber;
    cout << "請輸入生日 >> " << "\n";
    cin >> ptr->birthday;
    cout << "請輸入E-mail >> " << "\n";
    cin >> ptr->email;
    cout << "申請成功" << "\n";
    ptr->next = head->next;
    head->next = ptr;
    cout<<ptr->account<<' '<<ptr->password<<'\n';
    
    
} // register()



int main()  {
    int q = 0, choose = 0, n = 0;
    cur = (struct passenger *)malloc(sizeof(struct passenger));
    ptr = (struct passenger *)malloc(sizeof(struct passenger));
    head = (struct passenger *)malloc(sizeof(struct passenger));
    head->next = NULL;
    bool qq;
    a:
      cout << "1.會員登入" << "\n";
      cout << "2.會員註冊" << "\n";
      cout << "3.離開" << "\n" ;
      cin >> q;
      if ( q == 3 )  {
        cout << "感謝使用本系統";
        return 0;          
      }
      if ( q == 1 )  {
        accountlogin( qq );
        if ( qq == true ){
          goto b;
        }
        else  {
          goto a;
        }
      } // if
      
      if ( q == 2 )  {
        register1();
        goto a;
      } // if
      else {
        goto a;
      }
    b:
      cout << "歡迎回來，請選擇你要的功能" << "\n";
      cout << "1.訂票" << "\n";
      cout << "2.退票" << "\n";
      cout << "3.訂票資料查詢" << "\n";
      cout << "4.會員資訊查詢" << "\n";
      cout << "5.修改會員資料" << "\n";
      cout << "6.票價查詢" << "\n";
      cout << "7.登出系統" << "\n";
      cin >> choose;
      if ( choose == 1 ){}
      if ( choose == 2 ){}
      if ( choose == 3 ){}
      if ( choose == 4 )  {
        cout << "帳號 >> " << "\n";
        cout << cur->account << "\n";
        cout << "密碼 >> " << "\n";
        cout << cur->password << "\n";
        cout << "電話 >> " << "\n";
        cout << cur->phonenumber << "\n";
        cout << "生日 >> " << "\n";
        cout << cur->birthday << "\n";
        cout << "E-mail >> " << "\n";
        cout << cur->email << "\n";
        goto b;
      } // if
      if ( choose == 5 ){
          cout << "請選擇要修改的項目 " << "\n"; 
          cout << "1.密碼2.電話3.生日4.E-mail" << "\n";
          cin >> n ;
          if ( n == 1 ){
              cout << " 密碼 >>";
              cin >> cur->password;
          }
          else if ( n == 2 ){
              cout << " 電話號碼  >>";
              cin >> cur->phonenumber;
          }
          else if ( n == 3 ){
              cout << " 生日  >>";
              cin >> cur->birthday;
          }
          else if ( n == 4 ){
              cout << " EMAIL  >>";
              cin >> cur->email;
          }
          else {
              cout << "錯誤的輸入";
            
          }
          goto b;
          
      }
      if ( choose == 6 ){
        ticket1();
      }
      if ( choose == 7 )  {
        cout << "byebye";
        return 0;
      } // if
      
}  // main()


















