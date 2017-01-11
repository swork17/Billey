#ifndef CLIENT_H
# define CLIENT_H

	void init_client(int i_guichet);
	int connect_server(int i_guichet);
	int send_msg(int sock, char* message);

#endif /* !CLIENT_H */