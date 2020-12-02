CC := gcc
LDFLAGS := -lm
TARGETS := hw0401 hw0402-1 hw0402-2 hw0403 hw0403-1 hw0404 hw0405 hw0406
hw0401_OBJ := romannum.o
hw0402-1_OBJ := hanoi.o
hw0402-2_OBJ := hanoi.o
hw0403_OBJ := taylor.o
hw0403-1_OBJ := taylor.o
hw0404_OBJ := resistance.o
hw0405_OBJ := BAC.o

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
