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


DAC = [8, 11, 7, 1, 0, 5, 12, 6]
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

def getBin(n):
    s = bin(n)[2:]
    return '0' * (8 - len(s)) + s

def main():
    GPIO.setup(DAC, GPIO.OUT)

    try:
        while (True):
            s = input("Give a number from 0 to 255: ")

            try:
                n = int(s)

                if (n < 0):
                    print("Input an integer >= 0")
                    continue
                elif (n > 255):
                    print("Input an integer in [0..255]")
                    continue

                print(f"Voltage should be {float(n) * 3.3 / 256.0:.4f}")
                GPIO.output(DAC, list(map(int, getBin(n))))
            except ValueError:
                if s == 'q': break

                try:
                    n = float(s)
                    print("Input an integer!!!")
                except ValueError:
                    print("Input not a number!!!")

    finally:
        GPIO.output(DAC, [0] * len(DAC))
        
        


if __name__ == '__main__':
    main()
- Загрузите ветку в удалённый репозиторий с помощью команды отправки.