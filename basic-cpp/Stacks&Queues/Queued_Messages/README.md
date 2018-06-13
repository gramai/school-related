# Queued Messages _Eng._ 

Write a messaging system using QUEUES

### Requirements

- The messages will be received in the order they are send
- The classes needed are the following:
	- Message
	- MessageSender
	- MessageReceiver
- One QUEUE 'q' will be used which will hold objects of 'Message' type, used inside the classes.
- A 'Message' Object has:
	- A sender
	- A receiver
	- The contents
	- A date (create a struct or a class for the date)

- A message is places in a queue by an object called MessageSender which has the method 'putMessage' (enqueue)
- A message is removed from the queue (dequeue) by an object called MessageReceiver 

- The class used for QUEUE can receive all types of objects ( use a TEMPLATE CLASS)
- Test all the classes in a main function 



# Messages en file d'attente _Fr._

Faire une système de messagerie avec QUEUES ( Files d'attente)

### Les Tâches

- Les messages sont reçus dans l'ordre où ils sont envoyés
- Les classes concernées sont les suivantes:
	- Message
	- MessageSender
	- MessageReceiver
- On a une QUEUE q des objets de type Message, utilisée dans ces classes.
- Un objet Message a:
	- Un expéditeur; 
	- Un destinataire
	- Le contenu
	- Une date (faire un struct ou une classe pour la date)
- Un message est placé dans une file d'attente par un objet
MessageSender qui a une méthode « putMessage » (enqueue)
- Un message est supprimé de la file d'attente (dequeue) par un
objet de la classe MessageReceiver.
- Votre classe file d'attente (QUEUE) peut recevoir tous types
d'objets (TEMPLATE CLASS)
- Testez vos classes dans une fonction main.
