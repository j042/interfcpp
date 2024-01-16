program main
   use CallM
   implicit none


   call call_py()

   write(*, *) "called"

end program
