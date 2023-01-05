/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:28:43 by mgranero          #+#    #+#             */
/*   Updated: 2022/11/06 14:59:02 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;					
}					t_list;	

typedef struct s_loop_elm
{
	size_t	i;
	int		j;
	int		k;
	size_t	cnt;
	size_t	size_str;
}				t_loop_elm;

struct	s_mem
{
	void	**arr_allocd_mem;
	int		len_arr_allocd_mem;
	int		error_id;
};

enum e_error_mem {
	NO_ERR,
	ERR_MEM_ALLOC,
	ERR_MEM_CALLOC,
	ERR_MEM_DEALLOC,
	ERR_MEM_REALLOC,
	ERR_ADD_ALLCD_ARR,
	NUMBER_OF_ENUM_ERRORS
};

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_bzero(void *str, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size_of_type);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_error_manager(struct s_mem *mem);
int			ft_mem_dealloc(void *ptr_allocd, struct s_mem *mem);
void		ft_free_all_allocated_mem(struct s_mem *mem);
int			ft_add_allocd_2array(void *ptr_allocd, struct s_mem *mem);
void		*ft_mem_calloc(size_t size_desired, size_t size_type,
				struct s_mem *mem);
int			ft_remove_pointer_from_array(void *ptr_allocd,
				struct s_mem *mem, int index);

#endif
