/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:03:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/05 21:28:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ************************************************************************** */
/*                                 LIBRARIES                                  */
/* ************************************************************************** */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// Error strings
# include "str_error.h"

/* ************************************************************************** */
/*                               COLOR CONSOLE                                */
/* ************************************************************************** */
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define ORANGE		"\033[38;5;208m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define RESET		"\033[0m"

/* ************************************************************************** */
/*                               STRUCTURES                                   */
/* ************************************************************************** */

/**
 * ENGHISH:
 * 		This structure holds the configuration data for the philosophers
 * 		simulation.
 * 		It includes the number of philosophers, time intervals for various
 * 		actions, and an optional limit on how many times each philosopher must
 * 		eat.
 *
 * SPANISH:
 * 		Esta estructura contiene los datos de configuración para la simulación
 * 		de filósofos.
 * 		Incluye el número de filósofos, intervalos de tiempo para varias
 * 		acciones, y un límite opcional sobre cuántas veces debe comer cada
 * 		filósofo.
 *
 * @param number_of_philosophers:
 * 		The total number of philosophers in the simulation. |
 * 		El número total de filósofos en la simulación.
 *
 * @param time_to_die:
 * 		The time (in milliseconds) a philosopher can go without eating
 * 		before dying. |
 * 		El tiempo (en milisegundos) que un filósofo puede pasar sin
 * 		comer antes de morir.
 *
 * @param time_to_eat:
 * 		The time (in milliseconds) it takes for a philosopher to eat. |
 * 		El tiempo (en milisegundos) que tarda un filósofo en comer.
 *
 * @param time_to_sleep:
 * 		The time (in milliseconds) a philosopher spends sleeping. |
 * 		El tiempo (en milisegundos) que un filósofo pasa durmiendo.
 *
 * @param number_of_times_each_philosopher_must_eat [OPTIONAL]:
 * 		Optional parameter specifying how many times each philosopher must eat. |
 * 		Parámetro opcional que especifica cuántas veces debe comer cada filósofo.
 */
typedef struct s_data
{
	long				number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	int					eaters_count;
	pthread_mutex_t		eat_mtx;
	pthread_cond_t		eat_cond;
	volatile int		stop;
	long				start_time;
}	t_data;

/**
 * ENGHISH:
 * 		This structure represents a philosopher in the simulation.
 * 		It includes an identifier and a pointer to the next philosopher,
 * 		allowing for the creation of a linked list of philosophers.
 *
 * SPANISH:
 * 		Esta estructura representa a un filósofo en la simulación.
 * 		Incluye un identificador y un puntero al siguiente filósofo,
 * 		permitiendo la creación de una lista enlazada de filósofos.
 *
 * @param id:
 * 		The unique identifier for the philosopher. |
 * 		El identificador único del filósofo.
 *
 * @param thread:
 * 		The thread associated with the philosopher. |
 * 		El hilo asociado al filósofo.
 *
 * @param meals_eaten:
 * 		The number of meals the philosopher has eaten. |
 * 		El número de comidas que el filósofo ha comido.
 *
 * @param last_meal_ms:
 * 		The timestamp of the last meal the philosopher had (in milliseconds). |
 * 		La marca de tiempo de la última comida que tuvo el filósofo
 * 		(en milisegundos).
 *
 * @param left_fork_idx:
 * 		The index of the fork to the left of the philosopher. |
 * 		El índice del tenedor a la izquierda del filósofo.
 *
 * @param right_fork_idx:
 * 		The index of the fork to the right of the philosopher. |
 * 		El índice del tenedor a la derecha del filósofo.
 *
 * @param meal_mtx:
 * 		A mutex to protect access to the philosopher's meal data. |
 * 		Un mutex para proteger el acceso a los datos de comida del filósofo.
 *
 * @param finished:
 * 		A flag indicating whether the philosopher has finished eating. |
 * 		Una bandera que indica si el filósofo ha terminado de comer.
 */
typedef struct s_philosopher
{
	int					id;
	pthread_t			thread;
	int					meals_eaten;
	long				last_meal_ms;
	int					left_fork_idx;
	int					right_fork_idx;
	pthread_mutex_t		meal_mtx;
	int					finished;
	struct s_data		*data;
}	t_philosopher;

/* ************************************************************************** */
/*                           FUNCTION PROTOTYPES                              */
/* ************************************************************************** */

// Main function
 int				ft_philosophers(t_data *data);

// Utils functions
long			ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);

// Print functions
long			ft_putcolor(int fd, int color);
long			ft_putchar(char c, int fd);
long			ft_putstr(const char *str, int fd, int color);
long			ft_error(const char *function, char **str);

// Init functions
t_data			ft_construct_data(int argc, char **argv, char **envp);

// Thread functions
int				ft_create_thread(t_data *data);

// Mutex functions
int				ft_init_mutexes(pthread_mutex_t *forks,
					int number_of_philosophers);

// Time functions
void			ft_ms_sleep(long ms);
void			ft_ms_sleep_check(t_data *data, long ms);
long			ft_now_ms(void);
long			ft_timeval_to_ms(struct timeval *tv);

// Philosophers functions
t_philosopher	*ft_create_philosophers(t_data *data);
int				ft_destroy_philosophers(t_philosopher *philosophers);
int				ft_spawn_philosophers(t_philosopher *philosophers);
void			ft_print_status(t_data *data, int id, const char *msg);
void			*ft_philo_routine(void *arg);
void			*ft_take_forks_and_eat(t_philosopher *philo);
int				ft_start_eating(t_philosopher *philo);
void			*ft_monitor(void *arg);

// Forks functions
void			ft_take_forks(t_philosopher *p);
void			ft_put_forks(t_philosopher *p);

/* cleanup runtime resources */
int				ft_cleanup_data(t_data *data);

#endif
