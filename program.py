def divide(a, b):
    if b == 0:
        print("Error: Division by zero is not allowed.")
        return None  
    return a / b

def main():
    numerator = 10
    denominator = 0 
    result = divide(numerator, denominator)
    
    if result is not None:
        print(f"Result of division is: {result}")
    else:
        print("No result due to an error.")

if __name__ == "__main__":
    main()
