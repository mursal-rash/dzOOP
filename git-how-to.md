#### **1. Создание SSH-ключа**  
1. Откройте терминал (Linux/macOS) или Git Bash (Windows).  
2. Введите команду для генерации ключа (укажите свой email).  
3. Нажмите Enter, чтобы сохранить ключ в стандартную папку.  
4. При необходимости задайте пароль для защиты ключа (можно пропустить).  

#### **2. Добавление SSH-ключа в GitHub**  
1. Скопируйте содержимое файла с публичным ключом (`.pub`).  
2. Перейдите в **GitHub → Settings → SSH and GPG Keys**.  
3. Нажмите **New SSH Key**, вставьте ключ и сохраните.  

#### **3. Клонирование репозитория через SSH**  
1. На GitHub откройте нужный репозиторий.  
2. Нажмите **Code → SSH** и скопируйте ссылку.  
3. В терминале выполните команду `git clone` с этой ссылкой.  
4. Перейдите в папку репозитория.  

import RPi.GPIO as GPIO

GPIO.setwarnings(False)

dac = [8, 11, 7, 1, 0, 5, 12, 6]

GPIO.setmode(GPIO.BCM)
GPIO.setup(dac, GPIO.OUT)

def dec2bin(num):
    number = [0 for i in range(len(dac))]
    d_num = num % 256
    bin_num = bin(d_num)

    i = -1
    while bin_num[i] != 'b':
        number[i] = int(bin_num[i])
        i -= 1

    return number

try:
    while True:
        num = input()
        try:
            num = int(num)
            if 0 <= num <= 255:
                GPIO.output(dac, dec2bin(num))
                voltage = float(num) / 256.0 * 3.3
                print(f"Напряжение {voltage:.4} В")
            else:
                if num < 0:
                    print("Число должно быть положительным")
                elif num > 255:
                    print("Число больше 255")
        except Exception:
            if num == "q":
                break


finally:
    GPIO.output(dac, 0)
    GPIO.cleanup()