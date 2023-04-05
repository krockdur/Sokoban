FOR /L %%d IN (1 1 50 ) DO  (
   echo f | xcopy /f /y lvl.txt lvl_%%d.txt
)
