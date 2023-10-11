from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from base64 import *
import base64 
import sys
def decrypt(key, data):
    
    data = data.encode('utf-8')
    encodebytes = base64.decodebytes(data)
    cipher = AES.new(key.encode('utf-8'), AES.MODE_ECB)
    text_decrypted = cipher.decrypt(encodebytes)
    text_decrypted= text_decrypted.rstrip(b"\0")
    text_decrypted = text_decrypted.decode('utf-8')
    return text_decrypted
def generate_substitutions(s, index, current, result):
    if index == len(s):
        result.append(current)
        return

    if s[index] == '▆':
        for char in range (33,127):
            generate_substitutions(s, index + 1, current + chr(char), result)  # Replace ▆ with any character
    else:
        generate_substitutions(s, index + 1, current + s[index], result)

def all_substitutions(s):
    result = []
    generate_substitutions(s, 0, "", result)
    return result

input_string = "|q▆~k=▆&?I$Fx▆N▆"
substitutions = all_substitutions(input_string)
base64_encoded_ciphertext ="FZp57a6p84EUNC7I/ENj4RhPZtryOJr4che9JbA8ng1eI8ZMTlsl8kzicBDqkOqkFj3lwC69KR2MeA8lscVlig=="
i = 0
file_path = "log.txt"
for key in substitutions:
    i+=1
    

    # Decrypt the ciphertext and remove padding
    try:
        plain=decrypt(key, base64_encoded_ciphertext)
        print("Decrypted Text:", plain+' '+ key)
        with open(file_path, 'a') as file:
            file.write("\nDecrypted Text:"+ plain+' '+ key)
    # Convert the decrypted bytes to a string
    except Exception as e:
        print(f"Not Key No.{i} {key} {e}")
    else :
        print("Gotcha! Decrypted Text:", plain+' '+ "key:"+key)
        sys.exit()



    
