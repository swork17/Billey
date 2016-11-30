#ifndef SERVER_H
# define SERVER_H

	typedef struct s_info {
		char ipAddr[10];
		int numClient;
	}				t_info;

	int run_server();
	void *connection_handler(void *);
	void parseClientInfo(char *message, t_info *clientInfo);
	char **splitIt(char *string, t_info *clientInfo);

#endif /* !SERVER_H */