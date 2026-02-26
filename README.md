# Base-64-encoding-decoding-algorithm
Implementing a custom C Base64 encoding and decoding logic, enabling the conversion of standard ASCII text into Base64 format and the restoration of encoded strings back to their original ASCII representation.

## Usage

### Encode Text
	./a.out -encode <ascii_string>

### Decode Text
	./a.out -decode <base64_string>

## Command-Line Options

### Base64 Flags

* **`-encode`**
  Converts regular text into a Base64 string.
  https://www.base64encode.org/

* **`-decode`**
  Converts a Base64 string back into regular text.
  https://www.base64decode.org/

## Examples

### Encoding

	./a.out -encode Hello

This command takes the ASCII word `Hello` and translates it into the Base64 version which is `SGVsbG8=`.

### Decoding

	./a.out -decode V29ybGQ=

This command takes the Base64 word `V29ybGQ=` and translates it to ASCII version which is `World`.
