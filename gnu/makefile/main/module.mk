CFLAGS := -I$(staticLib_path) -I$(sharedLib_path)
LDFLAGS := -lstatic_test -lshared_test \
		-L$(staticLib_path) -L$(sharedLib_path) -Wl,-rpath,$(sharedLib_path)

local_dir := $(PWD)/main
local_src := $(addprefix $(local_dir)/,main.c)
main_objs := $(subst .c,.o,$(local_src))
local_target := $(local_dir)/main_test

$(local_target): $(main_objs) $(staticLib_target) $(sharedLib_target)
	$(CC) -o $@ $< $(LDFLAGS) $(CFLAGS)

