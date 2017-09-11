-- Pablo Bermejo
-- https://github.com/PabloAsekas/

module Pila where

data Pila a = P [a] deriving Show

pilaVacia :: Pila a
pilaVacia = P []

esPilaVacia :: Pila a -> Bool
esPilaVacia (P []) = True
esPilaVacia (P _) = False

apilar :: a -> Pila a -> Pila a
apilar x (P xs) = P (x:xs)

desapilar :: Pila a -> Pila a
desapilar (P (_:xs)) = P xs

cima :: Pila a -> a
cima (P (x:_)) = x