#ifndef CLIENT_H
# define CLIENT_H

	void  init_client(int i_guichet, int port);
	int   connect_server(int i_guichet, int port);
	char* send_msg(int sock, char* message);
	void  print_menu();

#endif /* !CLIENT_H */