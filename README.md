# ft_printf
Recreating the famous printf function!

This project replicates the behavior of the formats:
%  | format |
---|------|
`c` | character				|
`s` | string					|
`p` | pointer				|
`d` | decimal signed integer	|
`i` | integer				|
`u` | unsigned integer		|
`x` | hex integer (lowercase)|
`X` | hex integer (uppercase)|
`%` | just the %				|

and the flags: 
% | flag |
---|------|
`n`	| (number between % and the identifier) minimum field width						|
`-` 	| left justify 																	|
`0` 	| field padded with 0's instead of blanks										|
`.` 	| precision															|
`*` 	| indicates that the maximum or minimum field width will be passed as parameter	|


## Makefile

| Command | Usage |
| --- | --- |
| `make` | creates .o files for each function as well as the main library file, libft.a |
| `make clean` | removes the .o files used to create the library |
| `make fclean` | removes the .o & .a files used to create the library |
| `make re` | removes all .o & .a files then remakes them |

## tests
   
* [ft_printf_test](https://github.com/cacharle/ft_printf_test) by [Chacharle](https://github.com/cacharle)
* [PFT_EXAM](https://github.com/cclaude42/PFT_2019) by [César Claude](https://github.com/cclaude42)
* [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF) by [Mazoise](https://github.com/Mazoise)

