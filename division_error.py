# division_error.py
def divide_numbers(a, b):
    return a / b

# This will cause a division by zero error
result = divide_numbers(10, 0)
print(result)
