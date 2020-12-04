CC := gcc
LDFLAGS := -lm
TARGETS := hw0501 hw0502
hw0501_OBJ := iseven.o
hw0502_OBJ := deter.o
hw0503_OBJ :=
hw0504_OBJ :=
hw0405_OBJ :=

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
