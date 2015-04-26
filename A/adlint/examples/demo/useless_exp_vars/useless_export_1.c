int error_code;

char *mesg_tbl[] = {"error-1", "error-2", "error-3"};

void get_error_mesg(void)
{
    return mesg_tbl[error_code];
}
