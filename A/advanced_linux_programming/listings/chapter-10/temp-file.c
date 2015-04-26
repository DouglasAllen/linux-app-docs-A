/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

struct foo
{
  int x;
};

int main ()
{
  struct foo f;
  *((int*) &f) = 42;
  return f.x;
}
