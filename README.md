# MyProject - Modern C++ Library Template

A modern C++ project template with CMake integration, testing support, and proper packaging. Use this template to kickstart your C++ library development with best practices.

## Features

- Modern CMake setup with proper export/import configuration
- FetchContent support for easy integration
- Google Test integration for unit testing
- CPack configuration for multiple platforms
- GitHub Actions CI/CD ready
- Proper library versioning and symbol visibility

## Requirements

- CMake 3.15 or higher
- C++17 compatible compiler
- Git
- (Optional) Google Test for running tests

## Integration

### Using FetchContent

```cmake
include(FetchContent)
FetchContent_Declare(
    MyProject
    GIT_REPOSITORY https://github.com/username/MyProject.git
    GIT_TAG v1.0.0  # Specify a version tag
)
FetchContent_MakeAvailable(MyProject)

# Link against the library
target_link_libraries(your_target PRIVATE MyProject::mylib)
```

### Using find_package

```cmake
find_package(MyProject REQUIRED)
target_link_libraries(your_target PRIVATE MyProject::mylib)
```

## Building from Source

```bash
git clone https://github.com/username/MyProject.git
cd MyProject
mkdir build && cd build
cmake ..
cmake --build .
```

### Running Tests
```bash
cmake .. -DMYPROJECT_BUILD_TESTS=ON
cmake --build .
ctest --output-on-failure
```

## Usage Example

```cpp
#include <mylib/mylib.hpp>

int main() {
    mylib::Calculator calc;
    double result = calc.add(5.0, 3.0);
    return 0;
}
```

## Project Structure
```
.
├── .github/            # GitHub specific files (workflows, templates)
├── app/               # Example application
├── lib/               # Library source code
│   ├── include/      # Public headers
│   ├── src/          # Implementation files
│   └── cmake/        # CMake configuration files
└── tests/            # Test files
```

## Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](.github/CONTRIBUTING.md) for guidelines.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Template Usage

1. Click "Use this template" on GitHub
2. Replace "MyProject" with your project name in:
   - CMakeLists.txt files
   - README.md
   - .github/workflows/ci.yml
3. Update library headers and implementation
4. Update tests for your functionality
5. Update documentation

## Acknowledgments

- Modern CMake practices
- C++ best practices
- GitHub Actions for CI/CD