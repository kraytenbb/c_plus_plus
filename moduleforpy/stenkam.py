import time

def calculate_time():
    start_time = time.time()  # Запуск таймера

    data = [1, 2, 2, 3, 4, 4, 5]
    result = list(set(data))
    print(result)

    end_time = time.time()  # Завершение таймера
    time_taken = end_time - start_time  # Вычисление времени выполнения в секундах

    return time_taken

print(calculate_time())