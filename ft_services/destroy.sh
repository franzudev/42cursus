kubectl delete --all services --namespace=services
kubectl delete --all deployments --namespace=services
kubectl delete --all pods --namespace=services
kubectl delete --all sa --namespace=services
kubectl delete --all deployments --namespace=metallb-system
kubectl delete --all daemonsets --namespace=metallb-system
kubectl delete --all pods --namespace=metallb-system
kubectl delete --all services --namespace=kubernetes-dashboard
kubectl delete --all deployments --namespace=kubernetes-dashboard
kubectl delete --all pods --namespace=kubernetes-dashboard
kubectl delete --all sa --namespace=kubernetes-dashboard
kubectl delete --all services --namespace=data
kubectl delete --all deployments --namespace=data
kubectl delete --all sa --namespace=data
kubectl delete --all pvc --namespace=data
kubectl delete --all pv --namespace=data
kubectl delete namespaces services
kubectl delete namespaces data
kubectl delete namespaces kubernetes-dashboard
kubectl delete namespaces metallb-system

# Stop kubernetes-dashboard
lsof -t -i :8001 | xargs kill
