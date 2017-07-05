SET BAMBOO_URL=http://aydans-server.flaming-water.com:8085
SET BUILD_PLAN_KEY=TES-TP

echo "Bamboo Url: %BAMBOO_URL%"
echo "Build Plan Key: %BUILD_PLAN_KEY%"

echo "Retrieving the latest build result..."

curl -g "%BAMBOO_URL%/rest/api/latest/result/%BUILD_PLAN_KEY%?expand=results[0:0].result"

PAUSE