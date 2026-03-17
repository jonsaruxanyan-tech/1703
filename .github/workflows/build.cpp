name: Build

on:
  workflow_dispatch:
    inputs:
      file_name:
        description: "Input file name"
        required: true
        default: "hello.cpp"
        // type: choice
        // options:
        //   - a.cpp
        //   - b.cpp
        //   - c.cpp

jobs:
  cpp-build:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout repository
        uses: actions/checkout@v4

      - name: Install g++
        run: sudo apt-get update && sudo apt-get install -y g++

      - name: Compile C++ file
        run: g++ -std=c++17 ${{ inputs.file_name }} -o output

      - name: Run executable
        run: ./output
