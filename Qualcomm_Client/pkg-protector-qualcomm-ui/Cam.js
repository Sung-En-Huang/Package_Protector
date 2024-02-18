import { React, useState, useEffect, useRef } from "react";
import { StyleSheet, View, Button, Text } from "react-native";
import { Camera } from "expo-camera";
import * as MediaLibrary from "expo-media-library";

const CameraScreen = () => {
  const [hasPermission, setHasPermission] = useState(null);
  const cameraRef = useRef(null);

  useEffect(() => {
    (async () => {
      const { status } = await Camera.requestCameraPermissionsAsync();
      setHasPermission(status === "granted");
    })();
  }, []);

  const takePicture = async () => {
    if (cameraRef.current) {
      const photo = await cameraRef.current.takePictureAsync();

      // Request permission to access the media library
      const { status } = await MediaLibrary.requestPermissionsAsync();
      if (status === "granted") {
        // Save the photo to the gallery
        const asset = await MediaLibrary.createAssetAsync(photo.uri);
      }
    }
  };

  if (hasPermission === null) {
    return <View />;
  }
  if (hasPermission === false) {
    return <Text>No access to camera</Text>;
  }

  return (
    <View style={styles.top}>
      <View style={styles.outer}>
        <Camera style={styles.cam} ref={cameraRef}>
          {/* Camera view goes here */}
        </Camera>
      </View>
      <Button
        style={{ marginTop: "2em" }}
        title="IDENTITY VERIFICATION"
        onPress={takePicture}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  cam: {
    flex: 1,
    width: "100%",
  },
  outer: {
    flex: 1,
  },
  top: {
    flex: 1,
    maxHeight: "35%",
  },
});

export default CameraScreen;
