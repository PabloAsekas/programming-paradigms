-- Pablo Bermejo
-- https://github.com/PabloAsekas/

module Utilidades where

import Data.Char

--Lectura del archivo
separarLineas :: String -> [String]
separarLineas cadena = lines cadena

separarCaracteres :: [String] -> [[String]]
separarCaracteres [] = []
separarCaracteres (x:xs) = (words x) : (separarCaracteres xs)

--Saber si es dígito
esDigito :: String -> Bool
esDigito ('(':'-':xs) = True
esDigito (x:xs) = isDigit x

--Pasar una lista de listas de string a lista de strings

postfijaAString :: [[String]] -> [String]
postfijaAString [] = []
postfijaAString (x:xs) = [postfijaAStringAux x] ++ postfijaAString xs

postfijaAStringAux :: [String] -> String
postfijaAStringAux lista = unwords lista

--Mezclar dos listas en una intercalando los datos

mezclarDatos :: [String] -> [String] -> [String]
mezclarDatos [] [] = []
mezclarDatos (x:xs) (y:ys) = [x ++ " = " ++ y] ++ mezclarDatos xs ys