CC := gcc
LDFLAGS := -lm
TARGETS := hw0501 hw0502 hw0503 hw0504 hw0505
hw0501_OBJ := iseven.o
hw0502_OBJ := deter.o
hw0503_OBJ := polynomial.o
hw0504_OBJ := linearreg.o
hw0505_OBJ := minesweeper.o

.PHONY:all
all:$(TARGETS)

.SECONDEXPANSION:

$(TARGETS):$$($$@_OBJ)
	$(CC) $@.c $^ -o $@ $(LDFLAGS)

%.o:%.c
	$(CC) -c $^ -o $@


.PHONY:clean
clean:
	rm -rf $(TARGETS) $(foreach targ,$(TARGETS),$(foreach obj, $($(targ)_OBJ), $(obj)))
