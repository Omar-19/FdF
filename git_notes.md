# FdF

## man:

* ### mlx.1
#### NAME
       MiniLibX - Simple Graphical Interface Library for students

#### SYNOPSYS
       #include <mlx.h>

       void *
       mlx_init ();

#### DESCRIPTION
       MiniLibX  is an easy way to create graphical software, without any X-Win-
       dow/Cocoa programming knowledge. It provides simple  window  creation,  a
       drawing tool, image and basic events management.

#### BSD/LINUX X-WINDOW CONCEPT
       X-Window is a network-oriented graphical system for Unix.  It is based on
       two main parts:
       On one side, your software wants to draw something on the  screen  and/or
       get keyboard & mouse entries.
       On  the  other  side, the X-Server manages the screen, keyboard and mouse
       (It is often refered to as a "display").
       A network connection must be established between these  two  entities  to
       send  drawing  orders  (from  the  software  to  the  X-Server), and key-
       board/mouse events (from the X-Server to the software).

#### MACOSX CONCEPT
       The MacOSX operating system handle graphical access  to  the  screen  (or
       "display").
       On  one  side, your software wants to draw something on the screen and/or
       get keyboard & mouse entries.
       On the other side, the underlying MacOSX graphical framework that handles
       the screen, the windowing system, keyboard and mouse.
       A connection between these two entities must be established.

#### INCLUDE FILE
       mlx.h  should be included for a correct use of the MiniLibX API.  It only
       contains function prototypes, no structure is needed.

#### LIBRARY FUNCTIONS
       First of all, you need to initialize the connection between your software
       and  the display.  Once this connection is established, you'll be able to
       use other MiniLibX functions to send the graphical orders, like  "I  want
       to draw a yellow pixel in this window" or "did the user hit a key?".

       The  mlx_init  function  will  create  this connection. No parameters are
       needed, ant it will return a void * identifier, used for further calls to
       the library routines.

       All other MiniLibX functions are described in the following man pages:

       mlx_new_window      : manage windows

       mlx_pixel_put       : draw inside window

* ### mlx_loop.1
#### NAME
       MiniLibX - Handle events

#### SYNOPSYS
       int
       mlx_loop ( void *mlx_ptr );

       int
       mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

       int
       mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

       int
       mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

       int
       mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );

#### EVENTS
       Both  X-Window  and MacOSX graphical systems are bi-directionnal.  On one
       hand, the program sends orders to the screen to display  pixels,  images,
       and  so  on.  On the other hand, it can get information from the keyboard
       and mouse associated to the  screen.  To  do  so,  the  program  receives
       "events" from the keyboard or the mouse.

#### DESCRIPTION
       To receive events, you must use mlx_loop (). This function never returns.
       It is an infinite loop that waits for an event, and then  calls  a  user-
       defined  function  associated  with  this  event.   A single parameter is
       needed, the connection identifier mlx_ptr (see the mlx manual).

       You can assign different functions to the three following events:
       - A key is pressed
       - The mouse button is pressed
       - A part of the window should be re-drawn (this  is  called  an  "expose"
       event, and it is your program's job to handle it).

       Each window can define a different function for the same event.

       The    three   functions   mlx_key_hook   (),   mlx_mouse_hook   ()   and
       mlx_expose_hook () work exactly the same way.  funct_ptr is a pointer  to
       the  function you want to be called when an event occurs. This assignment
       is specific to the window defined by the win_ptr  identifier.  The  param
       adress  will be passed to the function everytime it is called, and should
       be used to store the parameters it might need.

       The syntax for the mlx_loop_hook () function is identical to the previous
       ones, but the given function will be called when no event occurs.

       When  it  catches an event, the MiniLibX calls the corresponding function
       with fixed parameters:

* ### mlx_new_image.1
#### NAME
       MiniLibX - Manipulating images

#### SYNOPSYS
       void *
       mlx_new_image ( void *mlx_ptr, int width, int height );

       char *
       mlx_get_data_addr  (  void *img_ptr, int *bits_per_pixel, int *size_line,
       int *endian );

       int
       mlx_put_image_to_window ( void *mlx_ptr, void  *win_ptr,  void  *img_ptr,
       int x, int y );

       unsigned int
       mlx_get_color_value ( void *mlx_ptr, int color );

       void *
       mlx_xpm_to_image  (  void  *mlx_ptr,  char  **xpm_data,  int  *width, int
       *height );

       void *
       mlx_xpm_file_to_image ( void *mlx_ptr, char *filename,  int  *width,  int
       *height );

       int
       mlx_destroy_image ( void *mlx_ptr, void *img_ptr );

#### DESCRIPTION
       mlx_new_image () creates a new image in memory. It returns a void * iden-
       tifier needed to manipulate this image later. It only needs the  size  of
       the  image  to be created, using the width and height parameters, and the
       mlx_ptr connection identifier (see the mlx manual).

       The user can draw inside the image (see below), and can  dump  the  image
       inside  a  specified window at any time to display it on the screen. This
       is done using mlx_put_image_to_window (). Three  identifiers  are  needed
       here, for the connection to the display, the window to use, and the image
       (respectively mlx_ptr , win_ptr and img_ptr ). The ( x , y )  coordinates
       define where the image should be placed in the window.

       mlx_get_data_addr  () returns information about the created image, allow-
       ing a user to modify it later. The img_ptr parameter specifies the  image
       to  use.  The three next parameters should be the addresses of three dif-
       ferent valid integers.  bits_per_pixel will be filled with the number  of
       bits  needed  to  represent  a  pixel color (also called the depth of the
       image).  size_line is the number of bytes used to store one line  of  the
       image  in  memory.   This  information is needed to move from one line to
       another in the image.  endian tells you wether the  pixel  color  in  the
       image needs to be stored in little endian ( endian == 0), or big endian (
       endian == 1).

* ### mlx_new_window.1
#### NAME
       MiniLibX - Managing windows

#### SYNOPSYS
       void *
       mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

       int
       mlx_clear_window ( void *mlx_ptr, void *win_ptr );

       int
       mlx_destroy_window ( void *mlx_ptr, void *win_ptr );

#### DESCRIPTION
       The  mlx_new_window () function creates a new window on the screen, using
       the size_x and size_y parameters to determine its size, and title as  the
       text  that  should  be  displayed in the window's title bar.  The mlx_ptr
       parameter is the connection identifier returned by mlx_init ()  (see  the
       mlx man page).  mlx_new_window () returns a void * window identifier that
       can be used by other MiniLibX calls.  Note that the MiniLibX  can  handle
       an arbitrary number of separate windows.

       mlx_clear_window  ()  and  mlx_destroy_window  ()  respectively clear (in
       black) and destroy the given window. They both have the same  parameters:
       mlx_ptr  is  the  screen  connection  identifier, and win_ptr is a window
       identifier.

#### RETURN VALUES
       If mlx_new_window() fails to create a new window (for  wathever  reason),
       it will return NULL, otherwise a non-null pointer is returned as a window
       identifier.  mlx_clear_window and  mlx_destroy_window  right  now  return
       nothing.

#### SEE ALSO
       mlx(3), mlx_pixel_put(3), mlx_new_image(3), mlx_loop(3)

* ### mlx_pixel_put.1
#### NAME
       MiniLibX - Drawing inside windows

#### SYNOPSYS
       int
       mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );

       int
       mlx_string_put  (  void *mlx_ptr, void *win_ptr, int x, int y, int color,
       char *string );

#### DESCRIPTION
       The mlx_pixel_put () function draws a defined pixel in the window win_ptr
       using  the  (  x  , y ) coordinates, and the specified color . The origin
       (0,0) is the upper left corner of the window, the x and  y  axis  respec-
       tively  pointing  right and down. The connection identifier, mlx_ptr , is
       needed (see the mlx man page).

       Parameters for mlx_string_put () have the same meaning. Instead of a sim-
       ple pixel, the specified string will be displayed at ( x , y ).

       In both functions, it is impossible to display anything outside the spec-
       ified window, nor display in another window in front of the selected one.

#### COLOR MANAGEMENT
       The  color parameter has an integer type. The displayed color needs to be
       encoded in this integer, following a defined scheme. All displayable col-
       ors can be split in 3 basic colors: red, green and blue. Three associated
       values, in the 0-255 range, represent how much of each color is mixed  up
       to  create the original color. Theses three values must be set inside the
       integer to display the right color. The three least significant bytes  of
       this integer are filled as shown in the picture below:

               | 0 | R | G | B |   color integer
               +---+---+---+---+

       While  filling the integer, make sure you avoid endian problems. Remember
       that the "blue" byte should always be the least significant one.

#### SEE ALSO
       mlx(3), mlx_new_window(3), mlx_new_image(3), mlx_loop(3)


### LINE DRAWING ALGORITHMS
* Xiaolin Wu's line algorithm
* Bresenham's line algorithm