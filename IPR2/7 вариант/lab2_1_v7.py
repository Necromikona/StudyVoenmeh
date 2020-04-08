import subprocess
import toml
import re
import time
import os

#args = ["lab2_1_v9.exe"]

if __name__== '__main__':
    tests = toml.load("testlab2_1_v7.toml")
    encoding = tests['encoding']
    result = ""
    
    for test in tests['testSuite']:
        args = tests['application']
        process = subprocess.Popen(args, stdin=subprocess.PIPE, stdout= subprocess.PIPE)
        
        # Цикл записи входных значений в поток
        # ввода и закрытие вводного потока         
        
        for input in test['input']:
            #print(input)
            process.stdin.write(bytes(input+os.linesep, encoding))      
        process.stdin.close()

        line=""
        line+=(str(process.stdout.read().decode(encoding)))
        #print(line)
        process.terminate()  


        flag = True
        for output in test['output']:
            #print(output)
            if re.match(output,line) is None:
                    result += 'Тест '+ str(test['number'])+ ': ' + str(test['name']) + ' – не пройден\n'
                    result += '\tОжидаемый результат: ' + output + '\n'
                    result += '\tРезультат работы: ' + line + '\n'
                    #result += '\tОжидаемый результат: ' + str(bytes(output,encoding)) + '\n'
                    #result += '\tРезультат работы: ' + str(bytes(line,encoding)) + '\n'
                    flag = False
                    break
            if flag:
                result += 'Тест '+ str(test['number'])+ ': ' + str(test['name']) + ' – пройден\n'



    print(result)
           