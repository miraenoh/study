import React from 'react';
import { StyleSheet, Text } from 'react-native';

const TextTitle = props => {
  return <Text style={{ ...styles.body, ...props.style }}>{props.children}</Text>;
};

const styles = StyleSheet.create({
  body: {
    fontFamily: 'open-sans-bold',
    fontSize: 18
  }
});

export default TextTitle;
