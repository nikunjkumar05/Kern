# Contributing to Kern

Thank you for your interest in contributing to Kern! This document outlines the guidelines for contributing to the project.

## Getting Started

1. Fork the repository and clone it locally.
2. Initialize submodules: `git submodule update --init --recursive`
3. Set up ESP-IDF v5.5.3 and source the environment: `source ~/esp/esp-idf/export.sh`
4. Build the project: `idf.py build` (or `just build`)

## Development Guidelines

### Architecture

Kern follows a strict layer separation:

- **`main/core/`** — Bitcoin logic. Must never depend on UI headers. Use callbacks for any user interaction.
- **`main/pages/`** — UI pages with create/show/hide/destroy lifecycle.
- **`main/ui/`** — Reusable LVGL UI primitives.
- **`main/qr/`** — QR scanning, parsing, and encoding.

Do not introduce UI dependencies into core modules. If a core function needs user confirmation, accept a callback parameter.

### Code Style

- Follow the existing style in the file you are modifying.
- Keep changes focused, one logical change per commit.

### Security

Kern is a Bitcoin signing firmware. Security is not optional.

- Never introduce network or radio functionality. The air-gap is by design.
- Use secure memory wipe (`WIPE` macros from `utils/`) for sensitive data.
- Use the existing `crypto_utils` wrappers around mbedtls rather than rolling custom crypto.
- Be mindful of stack usage on ESP32-P4, especially in deep call chains.

## Objectivity

We value focused, purposeful contributions. Every PR should clearly state **what problem it solves** — this helps reviewers understand your intent and keeps the project lean.

Whenever possible, link to a previously discussed **Issue** where the problem has been described and agreed upon. If no issue exists yet, consider opening one first to give the community a chance to weigh in. For small, self-evident fixes (typos, obvious bugs), describing the problem directly in the PR is perfectly fine.

## Submitting Changes

1. Create a branch from `master` with a descriptive name.
2. Make your changes in focused, well-described commits.
3. Ensure the project builds cleanly with `idf.py build`.
4. Open a Pull Request that:
   - References the related Issue (preferred), or clearly describes the problem being solved.
   - Explains **what** changed and **why**.
   - Notes any impact on security, memory usage, or the air-gap model.

## Reporting Issues

Open an Issue describing:

- **The problem** — what is wrong or missing, and why it matters.
- **Steps to reproduce** (for bugs).
- **Hardware and firmware version** (if relevant).

## License

By contributing, you agree that your contributions will be licensed under the [MIT License](LICENSE).
