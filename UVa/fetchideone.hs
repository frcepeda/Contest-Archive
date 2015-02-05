#!/usr/bin/env runghc

{-# LANGUAGE OverloadedStrings #-}

import qualified Data.Text as T
import qualified Data.Text.IO as T
import Text.Read
import Control.Applicative
import Control.Monad
import Control.Concurrent
import Network.HTTP
import System.Process
import System.IO
import Data.Monoid
import Data.Maybe

data Problem =
       Problem { codeURL :: T.Text
               , problemID :: T.Text
               , problemName :: T.Text
               , solver :: T.Text
               }
    deriving (Show, Eq)

tabs = T.split (== '\t')

toProblem [_,_,_,pid,pn,_,sol,code]
    = Problem { codeURL = code
              , problemID = pid
              , problemName = pn
              , solver = sol
              }

toFilename p = problemID p <> " - " <> problemName p <> ".cpp"
ideoneURL = T.replace "ideone.com/" "ideone.com/plain/" . codeURL

main = do
    T.putStrLn "Choose an option."
    T.putStrLn "1) Submit to UVa"
    T.putStrLn "2) Fetch solutions from Ideone"
    T.putStr   "> "
    hFlush stdout

    option <- readInt

    case option of
        1 -> submit
        2 -> fetchIdeone
        _ -> main

readInt = maybe 0 id . readMaybe <$> getLine

allProblems = map (toProblem . tabs) . T.lines <$> T.getContents
myProblems = filter ((== "Freddy") . solver) <$> allProblems

submit = do
    ps <- myProblems

    runCommand "uva use uva frcepeda"

    forM_ ps $ \p -> do
        waitForProcess =<< (runCommand . T.unpack $ "uva send " <> problemID p)
        threadDelay (2*10^6)

fetchIdeone = do
    ps <- myProblems

    let remaining = filter (("ideone" `T.isInfixOf`) . codeURL) ps

    forM_ remaining $ \p -> do
        Right response <- simpleHTTP . getRequest . T.unpack . ideoneURL $ p
        writeFile (T.unpack $ toFilename p) (rspBody response)
        T.putStrLn $ toFilename p
