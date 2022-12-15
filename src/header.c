/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:54:47 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/14 22:24:43 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_header(void)
{
	ft_putstr("\n\n\n\n\n"
		",,,,.,,,,..,,,**,,,**,,**/#%%#((/("
		"(#(#(#####((////((((###(///***,...            \n"
		",..,,....,,,,.,,,******//(#####%%#"
		"%%%%%%%######(((//////(((((///(/,..           \n"
		",,,,..,........,***,*//(((##%%%%%%"
		"&%%%%%&%%%%%%%%###(/////(((#(**//*            \n"
		",,,,,...,...,*/#(,*(##%%%&&&&&&&&&"
		"&&&&&&&&&&&&&&&%%%####(((((####/,*,           \n"
		",,.....,.,**///,*/(#%%&&&&&&&&&&@@"
		"&&&&&&&&&&&&&&&&%%%%%####((#####(*(*          \n"
		".....,,,*****,,*//(#%&&&&&&&&&&&@&"
		"&&&&@@@@&&&&&&&%%%%%%%####((##%%#(**,..       \n"
		"..,,/(*,,,,,,.,*(#(#%&&&@@@@&&&&&@"
		"&&@@&@@&&&&&&&&%%%%%%%%######%%%%%(/,         \n"
		"../*.,,,,,,**.,/***,,/#&&&&&&&&&&@"
		"&&&%%%%%&&&&&&%&%%%%%%%%%%##%%&%#(((*,    .   \n"
		".*...,*/,.*/,.,,..,*(#%%&&&&&&&&&&"
		"&&&%%%(*//(((&&&%%%%%%%%%###%&%%##///,...     \n"
		",...,*/*.,/(,.*(%%#%%%%%&&&&@@@@@@"
		"@&&&&&&&&&&&&&&&%%%%%&%%%%##%&&%#(//**,...    \n"
		".. .**,,.,*/.,(%%#(//(##(#%&@@@@@&"
		"&&&&%%##(#%&&&&&%#%%&%&%%%%%%&&%%%#(/,**,,.   \n");
	print_header_3();
}

void	print_header_2(void)
{
	ft_putstr("   .*,...,*, ,(#/,,***/(##*/&@@&&&"
		"&%%%#/*/(#(/(%&&%##%%%%%%%%%%&&&&%%%(//***/*. \n"
		"   ./....,/,.*//,/#* .,#((**&&&&&%"
		"%%#(#&(...*/(#&%%%#%%%%%#%%%&&%%%##(((/**//*..\n"
		" ...*.....,.,*/*,,,*/(#(%/*#&&&%%%"
		"%%#(((/**/((#%%%&&%%%%%###%%%%###(((//////***,\n"
		"   ...    ..**,/(((####(,./%&%%%%%"
		"%&%%##%%%#%%%###%%%%%%%###%%%##((//(((((*//*,,\n"
		"  . ..     .*(((%%%%##%/.*#%%%##%%"
		"&&&&&&&&&&%%%%#%%%%(#%#((###((//(#**,*(/((/(/,\n"
		"..     ..  ./%&%%%%%&%/,(%%%%##((%"
		"&&&&&&@@@&&&&&&&&%%#(((((/**(/*#%#//***/(####/\n"
		"        .  .(%&&%#%%%%*(%&@&&&%#(("
		"(%&@@&&&&&@@@&&&&%##((((/*,/(%%%&&##/##*(%%%#/\n"
		"           ./#%##%&&%,.*%&@@&&%%%&"
		"%##&&@@@@@&&&&&&&%##//((//*/#&&&&%#%&&&(/%&&%(\n"
		"      .... ./(/#%&&&#/*../((#(%%%#"
		"##%&&%&&@@@&&&&&%%%#//((//*(%&%%##%#%%%(#&&&%(\n"
		"    .      .///#%&%##%%%%&&&##%&%%"
		"&&&%&&%#%&&&&&&&&&%#/((///*#&&#(/((#%%#(%&&%#/\n"
		"        .  ./(*(((#%%%&&%&&&&&&&&%"
		"&&%%%%%%%%&&&%%&&&%(/((((/(&%%(*/*///((##(%#(/\n"
		"            ,//(/*//(#%#%%%%#%%%%%"
		"##%%%%%%%%%&&&&&&%#(/(#(/*,/#*.   .*///*..*,. \n");
}

void	print_header_3(void)
{
	print_header_2();
	ft_putstr("            .**/%#/,....,,*,,,**(("
		"/**///(%%%%&&&&&&%%(/%%(/,.                   \n"
		"             ,(*(&&%(,,/(((((#####"
		"#/* .*(#%(%&%%&&&&#/#%(,.                     \n"
		"              *#/#&@&**#%###((((##"
		"/*,/(%&&##&%#%&&&%/##/.                       \n"
		"               ,#(%&&*,#%###((((%("
		"*//(#&&&%%%##&&&%(%/                          \n"
		"                .((%&(.(%%%(((/#(*"
		"*/#%%%&&&&%#%&&#*,                           .\n"
		"                 .//%#,,(%#(#(((*/"
		"#%%&&&&&&&#%&#,                            ...\n"
		"                   .,##..(#(##(/%&"
		"&&&&&@&&&#%(.                            ..,,,\n"
		".                    .*(*.,*//#&@@"
		"&&&&&&&%*.                             ..,,,..\n"
		"..                     .*(#%&&&&&&"
		"&&&&#*                               ....,..,,\n"
		"\n\n\n\n\n");
}
