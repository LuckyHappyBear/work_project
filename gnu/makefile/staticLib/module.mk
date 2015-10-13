local_path := $(PWD)/staticLib
local_src := $(wildcard $(local_path)/*.c)
objs := $(subst .c,.o,$(local_src))
staticLib_target := $(local_path)/libstatic_test.a

$(staticLib_target): $(objs)
	$(AR) $(ARFLAGS) $@ $^

