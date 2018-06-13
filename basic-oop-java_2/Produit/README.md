# Product _Eng._

**Description**

Create a class, called Produit  _(Eng. Product)_ , that has:
- three private attributes : 
  - name (String)
  - price of fabrication (double)
  - VAT(int);
- a constructor without parameters;
- a constructor with 2 parameters (name and price of product);
- a constructor with all 3 parameters;
- three methods: 
  - getNom()  _(Eng. getName())_;
  - getPrix()  _(Eng. getPrice())_;
  - getVat();
- getters
- three methods: 
  - setNom(String nom)  _(Eng. setName(String name))_;
  - setPrix(double prix) _(Eng. setPrice(double price))_;
  - setVat(int v);  

This methods set values to attributes.

- setters
- a method prixDeVent()  _(Eng. sellingPrice())_, that calculates the selling price
- a method prixDeVent(int discount)  _(Eng. sellingPrice(int discount))_, that calculates the selling price after the discount

**Requirements**
1. Write a program in a class TestProduit  _(Eng. TestProduct) that
creates two products (two objects of the type Product) and prints
the sum of their selling price, under this form:
The products [product_name] and [product_name2] have the following
total price: [the sum of their prices]

2. Test the method prixDeVente()  _(Eng. sellingPrice()) without and 
with parameter

3. Create an ArrayList of Product objects and print all the 
product details (use a toString() method)

4. Then, print only the details of the most expensive product


# Produit _Fr._
**La Description**

Faites une classe, appelée Produit, qui a:
- trois attributs privés:
  - le nom (de type String)
  - le prix de fabrication (de type double)
  - VAT (statique, de type int);
- un constructeur sans paramètres;
- un constructeur avec 2 paramètres (pour le nom et le prix du produit);
- un constructeur avec tous les 3 paramètres;
- trois méthodes: 
  - getNom()
  - getPrix()
  - getVAT() qui renvoie le nom, le prix et le VAT du produit 
- des accesseurs (getters).
- trois méthodes: 
  - setNom(String nom)
  - setPrix(double prix),
  - setVAT(int v), pour établir le nom, le prix de fabrication et VAT pour chaque produit;
- des mutateurs (setters).
- une méthode prixDeVente() pour calculer le prix de vente.
- une méthode prixDeVente(int discount) pour établir le prix de vente avec discount.

**Les Tâches**

1. Ecrivez un programme (dans une classe
TestProduit) qui crée deux produis (2 objets de
type Produit) et affiche la somme de leurs prix de
vente, sous cette forme:
Les produits [nom_produit1] et [nom_produit2]
ont le prix total suivant: [la somme de leurs prix.]

2. Testez la méthode prixDeVente() avec et sans
paramètres pour le même produit

3. Créez un ArrayList d’objets Produit et affichez
tous les détails des produits (vous devez utiliser
une méthode toString()).
4. Puis, affichez seulement les détails du produit
le plus cher.
