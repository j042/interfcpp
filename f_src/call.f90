program main
  use, intrinsic :: ISO_C_BINDING
  implicit none

  interface

  subroutine call_py() bind (c, name="callme")
    import
  end subroutine call_py

  end interface

  call call_py()

  write(*, *) "called"

end program

