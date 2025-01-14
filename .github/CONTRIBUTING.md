# Contributing to MyProject

Thank you for your interest in contributing to MyProject! This document provides guidelines and instructions for contributing.

## Code of Conduct

This project adheres to a Code of Conduct. By participating, you are expected to uphold this code.

## How to Contribute

1. Fork the repository
2. Create a new branch for your feature/fix
3. Make your changes
4. Write or update tests
5. Ensure all tests pass
6. Submit a pull request

### Pull Request Process

1. Update the README.md with details of changes if needed
2. Update the version numbers following [Semantic Versioning](https://semver.org/)
3. The PR will be merged once you have the sign-off of at least one maintainer

## Coding Standards

- Follow the existing code style
- Use meaningful variable and function names
- Write clear commit messages
- Add comments for complex logic
- Include tests for new functionality

## Running Tests

```bash
mkdir build && cd build
cmake .. -DMYPROJECT_BUILD_TESTS=ON
cmake --build .
ctest --output-on-failure
```

## License

By contributing, you agree that your contributions will be licensed under the same license as the project. 