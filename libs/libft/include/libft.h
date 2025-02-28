/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:25:28 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/28 16:32:21 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */
/*                               INCLUDES                                     */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>

/* ************************************************************************** */
/*                                DEFINE                                      */
/* ************************************************************************** */

# define ERROR_ALLOC "Memory Allocation Failure !!"

/* ************************************************************************** */
/*                               vector2D                                     */
/* ************************************************************************** */

typedef struct s_vect2d
{
	double		x;
	double		y;
}	t_vect2d;

/* ************************************************************************** */
/*                                MEMORY                                      */
/* ************************************************************************** */

/**
 * Sets `len` bytes in `memory` to zero.
 *
 * @param memory Pointer to the memory block.
 * @param len    Number of bytes to zero out.
 * @return A pointer to 'memory'.
 */
void		*ft_bzero(void *memory, size_t len);

/**
 * Allocate memory and set its contents to zero.
 *
 * @param count	The number of elements to allocate.
 * @param size	The size (in bytes) of each element.
 * @return	A pointer to the allocated memory or NULL if allocation fails.
 */
void		*ft_calloc(size_t count, size_t size);

/**
 * Copies 'len' bytes of data from 'src' to 'dst'.
 *
 * @param dst  Destination memory area.
 * @param src  Source memory area.
 * @param len  Number of bytes to copy.
 * @return     Pointer to the destination memory area.
 */
void		*ft_memcpy(void *dst, const void *src, size_t len);

/**
 * Copies 'len' bytes of data from 'src' to 'dst', `handling overlap`.
 *
 * @param dst  Destination memory area.
 * @param src  Source memory area.
 * @param len  Number of bytes to copy.
 * @return     Pointer to the destination memory area.
 */
void		*ft_memmove(void *dst, const void *src, size_t len);

/**
 * Set 'len' bytes of `memory` to the specified `constant` value.
 *
 * @param memory   A pointer to the memory to be modified.
 * @param constant The value to set in each byte.
 * @param len      The number of bytes to set.
 * @return A pointer to the modified `memory`.
 */
void		*ft_memset(void *memory, int constant, size_t len);

/* ************************************************************************** */
/*                                PRINT                                       */
/* ************************************************************************** */

/**
 * Print an error message to the stderr.
 *
 * @param error_msg error message to print.
 * @note This function print only one message, if it hasn't been printed
 * before during the program's execution.
 */
void		ft_perror(char *error_msg);

/**
 * Write a string to the specified file descriptor.
 *
 * @param string string to write.
 * @param fd     The file descriptor to write to.
 */
void		ft_putstr_fd(char *string, int fd);

/* ************************************************************************** */
/*                                STRING                                      */
/* ************************************************************************** */

/**
 * Calculate the length of a string.
 *
 * @param string A pointer to the null-terminated string.
 * @return The length of the input string, excluding '\n'.
 */
int32_t		ft_strlen(const char *string);

/**
 * Compare two strings lexicographically.
 *
 * @param s1 A pointer to the first string.
 * @param s2 A pointer to the second string.
 * @return An integer value less than, equal to, or greater than zero
 */
int32_t		ft_strcmp(const char *s1, const char *s2);

/**
 * Replace occurrences of a character in a string with another character.
 *
 * @param str A pointer to string in which characters are to be replaced.
 * @param c1 The character to be replaced in the string.
 * @param c2 The character with which to replace 'c1'.
 */
void		ft_replace(char *str, char c1, char c2);

/**
 * ...
 *
 * @param string ...
 * @param character ...
 */
char		*ft_strchr(const char *string, int character);

/**
 * ...
 *
 * @param str ...
 */
int			ft_atoi(const char *str);

/* ************************************************************************** */
/*                              VECTOR 2D                                     */
/* ************************************************************************** */

/**
 * Add two 2D vectors together.
 *
 * @param vector1 The first 2D vector.
 * @param vector2 The second 2D vector.
 * @return A new 2D vector, the sum of `vector1` and `vector2`.
 */
t_vect2d	ft_add_vect2d(t_vect2d vector1, t_vect2d vector2);

/**
 * Normalize a 2D vector.
 *
 * @param vector The 2D vector to normalize.
 * @return A new 2D unit vector in the same direction
 * as the input vector.
 */
t_vect2d	ft_normalise_vect2d(t_vect2d vector);

/**
 * Rotate a 2D vector by a specified angle in radians.
 *
 * @param vector The 2D vector to rotate.
 * @param angle  The angle in radians by which to rotate the vector.
 * @return A new 2D vector resulting from rotating `vector` by `angle` radians.
 */
t_vect2d	ft_rotate_vect2d(t_vect2d vector, double angle);

/**
 * Scale a 2D vector by a specified factor.
 *
 * @param vector The 2D vector to scale.
 * @param scale  The scaling factor to apply to the vector.
 * @return A new 2D vector resulting from scaling `vector` by `scale`.
 */
t_vect2d	ft_scale_vect2d(t_vect2d vector, double scale);

#endif /* LIBFT_H */
//==============================================================================
