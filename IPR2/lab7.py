import subprocess
import toml
import re
import time
import os

if __name__== '__main__':
    tests = toml.load("tests74.toml")
    encoding = tests['encoding']
    result = ""

    for test in tests['testSuite']:
        with open("output.txt", 'wb') as file:
            args = test['applicationParameters']
            process = subprocess.Popen(args, stdin=subprocess.PIPE, stdout = file)
            for input in test['input']:
                process.stdin.write(bytes(input+os.linesep, encoding))
                process.stdin.flush()
                time.sleep(0.5)
            process.stdin.close()
            time.sleep(0.7)
            process.terminate()

        with open("output.txt", 'rb') as file:
            flag = True
            for output in test['output']:
                line = file.readline().decode(encoding)
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
    zoo = tests['fileDelete']
    os.remove(zoo)
