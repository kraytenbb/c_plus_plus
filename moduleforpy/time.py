import time
import random
import distinct_module

def calculate_time():
    start_time = time.time()

    data = []
    for i in range(1, 100000):
        data.append(i - random.randint(0,1))
    result = distinct_module.Distinct(data)
    print(result)
    print(sorted(data))

    time_taken = time.time() - start_time
    return time_taken

print(calculate_time())
