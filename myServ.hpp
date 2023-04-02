/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myServ.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:52:32 by fech-cha          #+#    #+#             */
/*   Updated: 2023/04/02 23:45:23 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSERV_HPP
# define MYSERV_HPP

#include "Socket.hpp"

class   polling
{
    private:
        std::vector<pollfd> _pollfds;
    public:
        polling(void);
        ~polling(void);
        
        int     callPoll(struct pollfd *fds, nfds_t nfds, int timeout);
        void    pushFd(int sockfd, int event);
        void    handlePoll(mySocket &sock, char *event);
        int     closeConnections(int fd);
        
        //getters
        nfds_t  getSize(void) const;
        const struct pollfd    *getPollfdAddrs(void) const;
};

#endif