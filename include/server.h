#ifndef SERVER_H
# define SERVER_H

	typedef struct s_info {
		char ipAddr[10];
		int numClient;
	}				t_info;

	typedef struct s_placeAttricut {
		char idZone[2];
		int nbPlaces;

	}				t_placeAttricut;

	int run_server();
	void *connection_handler(void *);
	void parseClientInfo(char *message, t_info *clientInfo);
	void parsePlaceAttribut(char *message, t_placeAttricut *attribut);

#endif /* !SERVER_H */