/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:31:29 by cjung             #+#    #+#             */
/*   Updated: 2021/01/15 14:05:37 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_info
{
	int		minus;
	int		zero;
	int		width;
	char	type;
	int		nbr_base;
	int		nbr_size;
	int		wild;
	int		colon;
	int		c_width;
	int		c_minus;
	int		c_zero;
	int		c_wild;
}				t_info;

size_t			parse_format(va_list ap, char *format);
void			parse_percent(va_list ap, t_info *info, \
char **format, size_t *ret);
int				ft_printf(const char *format, ...);
size_t			printf_format(va_list ap, t_info *info, char *format);

size_t			print_char(char c, t_info *info);
void			print_char_else(char c, t_info *info, size_t i);

size_t			print_str(char *str, t_info *info);
size_t			print_str_null(t_info *info);
void			print_str_minus(char *str, t_info *info, size_t *i, int *j);
void			print_str_else(char *str, t_info *info, size_t *i, int *j);
void			print_str_else2(char *str, t_info *info, size_t *i, int *j);
void			print_str_else3(char *str, t_info *info, size_t *i);

size_t			print_nbr(int n, t_info *info);
size_t			print_nbr_null(char *nbr, t_info *info, int *flags);
void			print_nbr_minus(int n, char **nbr, t_info *info, int *flags);
void			print_nbr_mflag(int n, char **nbr, t_info *info, int *flags);
void			print_nbr_mflag2(int n, char **nbr, int *flags);
void			print_nbr_minus2(int n, char **nbr, t_info *info, int *flags);

void			print_nbr_else(int n, char **nbr, t_info *info, int *flags);
void			print_nbr_else2(int n, char **nbr, t_info *info, int *flags);
size_t			print_nbr_clear(char *nbr, t_info *info, int *flags);

size_t			print_unbr(unsigned int n, t_info *info);
void			print_unbr_minus(unsigned n, t_info *info, size_t i);
void			print_unbr_else(unsigned n, t_info *info, size_t i);
void			print_unbr_zero(t_info *info, size_t i);

size_t			print_add(__uint64_t add, t_info *info);
size_t			print_add_null(t_info *info, size_t i);
void			print_add_null1(t_info *info, size_t *i);
void			print_add_null2(t_info *info, size_t *i);
void			print_add_minus(__uint64_t add, t_info *info, size_t i);
void			print_add_else(__uint64_t add, t_info *info, size_t i);

size_t			print_hex(unsigned n, t_info *info, int uorl);
void			print_hex_minus(unsigned n, t_info *info, int uorl, size_t i);
void			print_hex_else(unsigned n, t_info *info, int uorl, size_t i);
void			print_hex_else2(unsigned n, t_info *info, size_t i);

size_t			ft_unbrlen(t_info *info, __uint64_t n);
size_t			ft_nbrlen(t_info *info, int n);
void			info_init(t_info *info);
void			info_minus(t_info *info, int *flag);
void			info_width(t_info *info, char *format);
void			info_wild(int wild_num, t_info *info);
size_t			check_info(char *format, t_info *info, va_list ap);
size_t			check_info_while(char *format, t_info *info,\
va_list ap, int flag);
void			chekc_while_isdigit(char *format, t_info *info,\
int *flag, size_t flen);
void			info_colon(t_info *info, char *format, va_list ap);
void			info_colon_wild(t_info *info, va_list ap);
void			set_psize(char *p_size);

#endif
