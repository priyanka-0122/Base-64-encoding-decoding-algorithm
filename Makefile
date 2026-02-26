SRCS = main.c encoding.c decoding.c
EXECUTABLE = a.out

# 1. Collect all words typed after 'make encode_text'
# MAKECMDGOALS contains all arguments. filter-out removes 'encode_text' itself.

# 1. MAKECMDGOALS: A list of every word typed after 'make' (e.g., 'encode_text Hello')
# 2. words: Counts the total number of words in that list
# 3. wordlist 2, ...: Grabs from the 2nd word to the end, skipping the command name itself
ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

all:	$(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	gcc $(SRCS) -o $(EXECUTABLE)

encode_text:
	./$(EXECUTABLE) -encode $(ARGS)

# Doesn't work
# try running in CMDLINE as
# ./a.out -decode <-- STRING -->
# decode_text:
#	./$(EXECUTABLE) -decode $(ARGS)

# 2. This 'dummy' rule stops Make from looking for files 
# named after your input string (e.g., 'Hello')

# This 'catch-all' wildcard matches any extra words (like your input string)
# and tells Make to do nothing with them, preventing "No rule to make target" errors.
$(eval $(ARGS):;@:)

clean:
	rm -rf a.out
