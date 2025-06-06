# Assert

**Assert** is a lightweight C library providing helper macros to facilitate writing test cases for other libraries. It simplifies the process of validating code behavior by offering a set of intuitive assertions.

## Features

- **Simplified Assertions**: Easily validate conditions in your tests with straightforward macros.

- **Integration Examples**: Includes sample test cases demonstrating how to integrate the Assert library into your projects.

## Getting Started

To start using the Assert library in your project, follow these steps:

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/Ali-Mirghasemi/Assert.git
    ```

2. **Include in Your Project**: Incorporate the necessary source files from the Src directory into your project build.​

3. **Include the Header**: Add the following line at the beginning of your test files to access the assertion macros:
    
    ```c
    #include "Assert.h"
    ```

## Usage Example

Here's a basic example of how to use the Assert library in a test case:

```c
#include "Assert.h"

void test_addition() {
    int result = add(2, 3);
    assert(result, 5);
}
```

In this example, `assert` checks if the result of the add function equals 5.​

For more detailed examples, refer to the `Assert-Test` project in the Examples directory.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
