import os
from datetime import datetime


LOG_FILE = "utils/log.txt"
DATASET_FOLDER = "datasets"


def display(message):
    print(message)


def write_log(option):
    os.makedirs("utils", exist_ok=True)

    with open(LOG_FILE, "a") as file:
        time = datetime.now()
        file.write(str(time) + " - " + option + "\n")


def analyze_file():
    filename = input("Enter dataset file name: ")

    path = DATASET_FOLDER + "/" + filename

    if os.path.exists(path):

        with open(path, "r") as file:
            text = file.read()

        characters = len(text)
        words = len(text.split())
        lines = len(text.splitlines())

        unique_characters = len(set(text))

        frequency = {}

        for char in text.lower():
            if char.isalpha():
                if char in frequency:
                    frequency[char] += 1
                else:
                    frequency[char] = 1

        display("File Analysis")
        display("Characters: " + str(characters))
        display("Words: " + str(words))
        display("Lines: " + str(lines))
        display("Unique Characters: " + str(unique_characters))
        display("Letter Frequency:")

        for key, value in frequency.items():
            print(key, ":", value)

    else:
        display("File not found")


def menu():

    while True:

        display("\nCryptoLabX Toolkit")
        display("1. Encrypt")
        display("2. Decrypt")
        display("3. Attack")
        display("4. Analyze")
        display("5. Exit")

        choice = input("Select option: ")

        if choice == "1":
            write_log("Encrypt")
            display("Coming Soon")

        elif choice == "2":
            write_log("Decrypt")
            display("Coming Soon")

        elif choice == "3":
            write_log("Attack")
            display("Coming Soon")

        elif choice == "4":
            write_log("Analyze")
            analyze_file()

        elif choice == "5":
            write_log("Exit")
            display("Program closed")
            break

        else:
            display("Invalid option")


if __name__ == "__main__":
    menu()
