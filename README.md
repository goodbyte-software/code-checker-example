# Code checker example

This repository demonstrates how to run a static code analysis tool (namely CodeChecker) that is integrated with Zephyr workspace.

## Prerequisites

To use this repository, you must have the following tools installed:
- `west`
- `Zephyr SDK`
- `CodeChecker`
- `clang-tidy`

## Getting Started

1. **Clone the repository**:
    Begin by cloning this repository to your local machine.

2. **Initialize the workspace**:
    Use `west` to set up your Zephyr workspace:
    ```bash
    west init -l app && west update
    ```

3. **Build the application**:
    Compile your application for the custom board:
    ```bash
    west build -b qemu_cortex_m3 app --pristine
    ```

4. **Run CodeChecker analysis**
    Run west with SCA variant specified
    ```bash
    west build -b qemu_cortex_m3 app --pristine -- -DZEPHYR_SCA_VARIANT=codechecker
    ```

## Support

If you encounter any issues or have questions regarding the setup, please file an issue in this repository's Issue Tracker.

## Contributing

Contributions are welcome! If you'd like to improve the example, please submit a pull request.
