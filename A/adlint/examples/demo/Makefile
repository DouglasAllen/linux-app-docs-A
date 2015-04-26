DIRS = \
ambig_operator \
arg_points_unset \
array_range \
bad_bitfields \
bad_brace \
bad_charset \
bad_comment \
bad_const \
bad_conv \
bad_enum \
bad_include \
bad_indent \
bad_init \
bad_label \
bad_line \
bad_macro \
bad_return \
bitwise_expr \
call_by_value \
cross_ref \
dangling_else \
dead_code \
deep_nest \
dense_switch \
direct_recur \
div_by_zero \
dos_source \
funptr_cast \
goto_stmt \
id_hiding \
ill_defined \
implicit_conv \
implicit_int \
incomplete_ifelse \
incomplete_type \
indirect_recur \
inline_asm \
integer_promotion \
intro_demo \
invalid_call \
kandr_fundef \
line_comment \
local_decl \
logical_expr \
logical_trick \
long_sym \
loop_var \
malloc_or_die \
may_be_null \
may_be_null_arith \
may_be_unset \
mmapped_io \
multi_break \
multi_decl \
multi_def \
multi_typedef \
must_be_false \
must_be_null \
must_be_null_arith \
must_be_true \
no_eof_nl \
no_void_arg \
null_stmt \
octal_const \
output_by_param \
overflow \
press_release \
redundant_select \
register_vars \
reserved_ident \
retn_lvar_addr \
sequence_point \
shift_expr \
should_be_typedef \
static_paths \
static_vars \
tag_hiding \
typedef_each_src \
tricky_incdec \
undefined_macro \
uninit_vars \
union_type \
unmatch_decl \
unmatch_paren_macro \
unnamed_member \
unreachable \
useless_exp_funs \
useless_exp_vars \
useless_expr \
useless_funs \
useless_header \
useless_vars \
va_funcall \
various_fundef \
wchar_wstring \
wrap_around

.PHONY: adlintize
adlintize:
	@for i in $(DIRS); do (\
	    cd $$i; \
	    if [ ! -d adlint ]; then \
	        adlintize -o adlint; \
	    fi \
	) done

.PHONY: all
all : adlintize
	@for i in $(DIRS); do (\
	    cd $$i/adlint; \
	    make all 2>/dev/null; \
	) done

.PHONY: verbose-all
verbose-all : adlintize
	@for i in $(DIRS); do (\
	    cd $$i/adlint; \
	    make verbose-all; \
	) done

.PHONY: clean
clean :
	@-for i in $(DIRS); do ( cd $$i/adlint && make clean; ) done
	@for i in $(DIRS); do ( rm -rf $$i/adlint; ) done
