/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

// chained list type
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

// conversion + memory + chained list functions
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstfirst(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lst_push(t_list *lst, void *content);

typedef struct s_philo {
	int				id;
	int				time_die;
	int				nb_eat;
	int				fork_taken_by;
	long long		last_eat_timestamp;
	pthread_mutex_t	nb_eat_mtx;
	pthread_mutex_t	fork_taken_by_mtx;
	pthread_mutex_t	last_eat_timestamp_mtx;
	pthread_t		thread;
}	t_philo;

typedef struct s_cave {
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				min_eat;
	int				max_eat;
	int				exit;
	int				died_id;
	long long		start_timestamp;
	long long		died_timestamp;
	pthread_mutex_t	min_eat_mtx;
	pthread_mutex_t	exit_mtx;
	pthread_t		doctor_thread;
	t_list			*philo_lst;
}	t_cave;

typedef struct s_routine_thread {
	t_list				*philo_lst;
	t_cave				*cave;
}	t_routine_thread;

# define E_ARGS "Error : Bad arguments !\n"

// print message with timestamp
void		msg_log(t_cave *cave, int id, char *msg, long long timestamp);

// create, init and fill cave and philosphers
int			create_philo(t_cave *cave);
t_list		*get_left_philo(t_list *philo);
void		init_cave(t_cave *cave);
int			set_cave_param(t_cave *cave, char **argv);
int			fill_cave(t_cave *cave);

// exit and cleaning
int			error_exit(t_cave *cave, char *str);
int			normal_exit(t_cave *cave);

// philosophers actions
void		philo_action(t_cave *cave, t_philo *philo, t_philo *left_philo, \
void *routine_thread);
void		philo_sleep(t_cave *cave, t_philo *philo);
void		philo_think(t_cave *cave, t_philo *philo);
int			philo_take_two_fork(t_cave *cave, t_philo *philo, \
t_philo *left_philo);
int			philo_eat(t_cave *cave, t_philo *philo, \
t_philo *left_philo);

// doctor actions
void		doctor_action(t_cave *cave, t_list *lst, int philo_hungry);

// routines
void		*routine_philo(void *routine_thread);
void		*routine_coroner(void *routine_thread);
void		*routine_cook(void *routine_thread);
void		routine_cave(t_cave *cave);

// getters of time in milliseconds
long long	ms_timestamp(void);
long long	ms_from_start(t_cave *cave);
long long	ms_betwen(long long t1, long long t2);
long long	ms_from_last_eat(t_philo *philo);
void		ms_sleep(t_cave *cave, int time);

// accessor protected by mutex
int			philo_eq_min_eat(t_cave *cave, t_philo *philo);
void		philo_set_last_eat(t_philo *philo);
long long	philo_get_last_eat(t_philo *philo);
int			philo_get_nb_eat(t_philo *philo);
void		philo_increase_nb_eat(t_philo *philo);
int			philo_get_fork_taken_by(t_philo *philo);
void		philo_set_fork_taken_by(t_philo *philo, int philo_id);
void		cave_set_exit(t_cave *cave);
int			cave_get_exit(t_cave *cave);
void		cave_increase_min_eat(t_cave *cave);
void		cave_set_min_eat(t_cave *cave, t_philo *philo);

#endif