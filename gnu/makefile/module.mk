RM := rm -f

staticLib_path = $(PWD)/staticLib/
sharedLib_path = $(PWD)/sharedLib/


main_test_target := $(PWD)/main/main_test
staticLib_target := $(PWD)/staticLib/libstatic_test.a
sharedLib_target := $(PWD)/sharedLib/libshared_test.so

include main/module.mk
include staticLib/module.mk
include sharedLib/module.mk

.PHONY: clean
clean:
	$(RM) $(staticLib_target) $(sharedLib_target) $(main_test_target)
	$(RM) */*.o -f
	$(RM) */*~
