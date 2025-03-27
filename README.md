# ATM Controller Project

This project is a simple ATM controller development project. 
The project provides the core functionalities of an ATM which handles some tasks such as authentication(CardNumber, PIN, AccoutName), checking balance, deposit, withdrawal, and also provides a simulation environment about simple ATM control with simulated card injection/ejection and bank account.

---

## Key Features

- **ATM Control** :  Authentication, Checking Balance, Deposit, Withdrawal, Hardware Control (CardReader)
- **Simulated Hardware** : Simplified CardReader (Injection, Ejection, Reading CardNumber)  
- **Simulated Bank** : Simplified Bank Account System (Create, Validate, Balance, Deposit, Withdrawal)

---

## Project Structure

```plaintext
ATM_CONTROLLER/
├── src/
│   ├── Account.h
│   ├── Account.cpp
│   ├── Hardware.h
│   ├── Hardware.cpp
│   ├── BankServer.h
│   ├── BankServer.cpp
│   ├── ATMController.h
│   └── ATMController.cpp
|   └── main.cpp
├── tests/
│   ├── test_Account.cpp
│   ├── test_ATMController.cpp
│   ├── test_BankServer.cpp
│   ├── test_Hardware.cpp
│   └── test_main.cpp
├── CMakeLists.txt
├── .gitignore
└── README.md
```

- **src/**: Source code for the ATM controller.
- **tests/**: Test code for ATM Controller classes. `test_main.cpp` file runs all tests.
- **CMakeLists.txt**: Build configuration.
- **.gitignore**: Git ignore configuration.
- **README.md**: Guide Document for the project.


---

## How to build & Test

### 1. Prerequisites

- Install **GCC 8.XX (MinGW-w64)** and **CMake**.
- This project was developed in Windows.
- Ensure both MinGW-w64 and CMake binary directories are added to your system's environment variable (`PATH`).

### 2. Build Instructions

Open a terminal in the project's root directory and execute:

```shell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### 3. Running Tests

After successful build, you can run tests by executing:

```shell
cd build
ctest
```

