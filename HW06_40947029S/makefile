CC := gcc
LDFLAGS := -lm
TARGETS := hw0601 hw0602 hw0603 hw0604 hw0605
hw0601_OBJ :=
hw0602_OBJ := reun.o
hw0603_OBJ := rotate.o
hw0604_OBJ := projection.o
hw0605_OBJ := card.o

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
