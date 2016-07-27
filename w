# watcher

while true; do
  scp * ec2:~/github/usaco/${PWD##*/}
  sleep 5
done
